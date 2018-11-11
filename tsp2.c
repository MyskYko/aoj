#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <unistd.h>

#define WIDTH 70
#define HEIGHT 40
#define MAX_NCITIES 1000
#define INITIAL_T 10000000000
#define r 0.99999

typedef struct
{
  int x;
  int y;
} City;

City city[MAX_NCITIES];
char map[WIDTH][HEIGHT];

int max(const int a, const int b)
{
  return (a > b) ? a : b;
}

void draw_line(const int x0, const int y0, const int x1, const int y1)
{
  int i;
  const int n = max(abs(x1 - x0), abs(y1 - y0));
  for (i = 0; i <= n; i++) {
    const int x = x0 + i * (x1 - x0) / n;
    const int y = y0 + i * (y1 - y0) / n;
    if (map[x][y] == ' ') map[x][y] = '*';
  }
}

void draw_route(const int n, const int *route)
{
  if (route == NULL) return;

  int i;
  for (i = 0; i < n; i++) {
    const int c0 = route[i];
    const int c1 = (i < n - 1) ? route[i+1] : route[0];
    draw_line(city[c0].x, city[c0].y, city[c1].x, city[c1].y);
  }
}

void plot_cities(FILE *fp, const int n, const int *route)
{
  int i, j, x, y;

  fprintf(fp, "----------\n");

  memset(map, ' ', sizeof(map));

  for (i = 0; i < n; i++) {
    char buf[100];
    sprintf(buf, "C_%d", i);
    for (j = 0; j < strlen(buf); j++) {
      const int x = city[i].x + j;
      const int y = city[i].y;
      map[x][y] = buf[j];
    }
  }

  draw_route(n, route);
    
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      const char c = map[x][y];
      fputc(c, fp);
    }
    fputc('\n', fp);
  }

  fflush(fp);
}

double distance(const int i, const int j)
{
  const double dx = city[i].x - city[j].x;
  const double dy = city[i].y - city[j].y;
  return sqrt(dx * dx + dy * dy);
}

double cal_distance(int n, int route[]) {
  int i;
  double sum_d = 0;
  for (i = 0; i < n; i++) {
    const int c0 = route[i];
    const int c1 = (i < n - 1) ? route[i+1] : route[0];
    sum_d += distance(c0, c1);
  }
  return sum_d;
}

double climb(const int n, int route[],double now_d) {
  int i, j,temp;
  i = 1;
  while(i < n) {
    for(j = i+1; j < n; j++) {
      temp = route[i];
      route[i] = route[j];
      route[j] = temp;
      double d = cal_distance(n,route);
      if(now_d > d) return d;
      temp = route[i];
      route[i] = route[j];
      route[j] = temp;
    }
    i++;
  }
  return now_d;
}

double annealing(const int n, int route[],double now_d,double T) {
  int i, j,temp;
  i = rand()%n;j = rand()%n;
  temp = route[i];
  route[i] = route[j];
  route[j] = temp;
  double d = cal_distance(n,route);
  if(exp((now_d-d)/T) > (double)rand()/RAND_MAX) return d;
  temp = route[i];
  route[i] = route[j];
  route[j] = temp;
  
  return now_d;
}

double solve(const int n, int route[])
{
  int i,j;
  double d,min_d;
  int temp_route[MAX_NCITIES];

  for(i = 0; i < n; i++) temp_route[i] = i;
  d = cal_distance(n,temp_route);
  min_d = d;
  for(i = 0; i < n; i++) route[i] = temp_route[i];
  
  for(j = 1; j < n; j++) {
    for(i = 0; i < n; i++) temp_route[i] = i;
    for(i = 0; i < j; i++) temp_route[i] = j-i-1;
    double T = INITIAL_T;
    while(T > 1) {
      d = annealing(n,temp_route,d,T);
      if(min_d > d) {
	min_d = d;
	for(i = 0; i < n; i++) route[i] = temp_route[i];
      }
      T *= r;
    }
  }
		     
  return min_d;
}

int main(const int argc, const char **argv)
{
  FILE *fp;
  const char *map_file = "map.txt";
  if ((fp = fopen(map_file, "a")) == NULL) {
    fprintf(stderr, "error: cannot open %s.\n", map_file);
    return 1;
  }

  if (argc != 2) {
    fprintf(stderr, "error: please specify the number of cities.\n");
    exit(1);
  }

  const int n = atoi(argv[1]);
  assert(n > 1 && n <= MAX_NCITIES);

  int i;
  for (i = 0; i < n; i++) {
    city[i].x = rand() % (WIDTH - 5);
    city[i].y = rand() % HEIGHT;
  }

  plot_cities(fp, n, NULL);
  sleep(1);

  int route[MAX_NCITIES];
  const double d = solve(n, route);

  printf("total distance = %f\nroute = ", d);
  for(i = 0; i < n; i++) printf("%d ",route[i]);
  printf("\n");
  plot_cities(fp, n, route);

  return 0;
}
