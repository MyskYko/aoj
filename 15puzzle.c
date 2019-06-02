#include <iostream>
#include <cstdlib>
#include <cstdio>

#define HEAP_SIZE 5000000
#define HASH_SIZE 10000000
#define MAX_STEPS 45

typedef struct _node {
	unsigned long long data;
	int steps;
	int f;
	struct _node * next;
} node;

unsigned int hash(unsigned long long data) {
	unsigned long long hash = 0;
	hash += data * 9966091;
	return (unsigned int)(hash % HASH_SIZE);
}

node * hash_unique_create(node ** hash_table, unsigned long long data, int steps, int f) {
	unsigned int hash_value = hash(data);
	//std::printf("%016llx, %x, %d\n", data, hash_value, steps);
	node * p = hash_table[hash_value];
	if (p == NULL) {
		node *q = (node*)malloc(sizeof(node));
		q->data = data;
		q->steps = steps;
		q->f = f;
		q->next = NULL;
		hash_table[hash_value] = q;
		return q;
	}
	if (p->data == data) {
		if (p->steps > steps) {
			p->f = f;
			p->steps = steps;
			return p;
		}
		return NULL;
	}
	while (p->next != NULL) {
		p = p->next;
		if (p->data == data) {
			if (p->steps > steps) {
				p->f = f;
				p->steps = steps;
				return p;
			}
			return NULL;
		}
	}

	node *q = (node*)malloc(sizeof(node));
	q->data = data;
	q->steps = steps;
	q->f = f;
	q->next = NULL;
	p->next = q;
	return q;
}

int Mdistance(unsigned long long data) {
	int distance[16];
	for (int j = 1; j < 16; j++) {
		distance[j] = 0;
		for (int i = 0; i < 16; i++) {
			unsigned int a;
			a = data >> (60 - 4 * i);
			a = a % 16;

			if ((int)a == j) {
				distance[j] = 0;
				distance[j] += std::abs(i % 4 - (j - 1) % 4);
				distance[j] += std::abs(i / 4 - (j - 1) / 4);
			}
		}
	}

	int sum = 0;
	for (int j = 1; j < 16; j++) {
		sum += distance[j];
	}
	return sum;
}

void heap_add(node ** heap, int * n, node * a) {
	*n += 1;
	int tmp_n = *n;
	while (tmp_n != 1) {
		if (heap[tmp_n / 2]->f > a->f) {
			heap[tmp_n] = heap[tmp_n / 2];
			tmp_n = tmp_n / 2;
		}
		else {
			break;
		}
	}
	heap[tmp_n] = a;
}

void heap_delete(node ** heap, int * n, int i) {
	if (i == 1) {
		heap[1] = heap[*n];
		*n -= 1;
	}

	if (2 * i > *n) {
		return;
	}
	if (2 * i + 1 > *n) {
		if (heap[i]->f > heap[2 * i]->f) {
			node * tmp = heap[i];
			heap[i] = heap[2 * i];
			heap[2 * i] = tmp;
		}
		return;
	}

	if (heap[i]->f < heap[2 * i]->f && heap[i]->f < heap[2 * i + 1]->f) {
		return;
	}

	if (heap[2 * i]->f < heap[2 * i + 1]->f) {
		node * tmp = heap[i];
		heap[i] = heap[2 * i];
		heap[2 * i] = tmp;
		heap_delete(heap, n, 2 * i);
	}
	else {
		node * tmp = heap[i];
		heap[i] = heap[2 * i + 1];
		heap[2 * i + 1] = tmp;
		heap_delete(heap, n, 2 * i + 1);
	}
}

/*
At the end, return 1; otherwise, return 0;
*/
int create(unsigned long long data, int steps, int f,
	node ** hash_table, node ** heap, int * n)
{
	node * p = hash_unique_create(hash_table, data, steps, f);
	if (p == NULL) {
		return 0;
	}

	if (data == 0x123456789abcdef0) {
		return 1;
	}

	if (steps == MAX_STEPS) {
		return 0;
	}

	heap_add(heap, n, p);
	if (*n > HEAP_SIZE) {
		printf("heap is full\n");
		throw 1;
	}

	return 0;
}

int find_zero(unsigned long long data) {
	for (int i = 0; i < 16; i++) {
		unsigned int a;
		a = data >> (60 - 4 * i);
		a = a % 16;

		if (a == 0) {
			return i;
		}
	}
	return 0;
}

// zero does move.

unsigned long long move_right(unsigned long long data, int zero_index, int * dif_f) {
	unsigned long long a;
	a = (data >> (60 - 4 * (zero_index + 1))) % 16;
	if (((int)a - 1) % 4 < (zero_index + 1) % 4) {
		*dif_f = 0;
	}
	else {
		*dif_f = 2;
	}
	a = a << (60 - 4 * (zero_index + 1));
	unsigned long long b;
	b = data - a;
	a = a << 4;
	b += a;

	return b;
}

unsigned long long move_left(unsigned long long data, int zero_index, int * dif_f) {
	unsigned long long a;
	a = (data >> (60 - 4 * (zero_index - 1))) % 16;
	if (((int)a - 1) % 4 > (zero_index - 1) % 4) {
		*dif_f = 0;
	}
	else {
		*dif_f = 2;
	}
	a = a << (60 - 4 * (zero_index - 1));
	unsigned long long b;
	b = data - a;
	a = a >> 4;
	b += a;

	return b;
}

unsigned long long move_down(unsigned long long data, int zero_index, int * dif_f) {
	unsigned long long a;
	a = (data >> (60 - 4 * (zero_index + 4))) % 16;
	if (((int)a - 1) / 4 < (zero_index + 4) / 4) {
		*dif_f = 0;
	}
	else {
		*dif_f = 2;
	}
	a = a << (60 - 4 * (zero_index + 4));
	unsigned long long b;
	b = data - a;
	a = a << 16;
	b += a;

	return b;
}

unsigned long long move_up(unsigned long long data, int zero_index, int * dif_f) {
	unsigned long long a;
	a = (data >> (60 - 4 * (zero_index - 4))) % 16;
	if (((int)a - 1) / 4 > (zero_index - 4) / 4) {
		*dif_f = 0;
	}
	else {
		*dif_f = 2;
	}
	a = a << (60 - 4 * (zero_index - 4));
	unsigned long long b;
	b = data - a;
	a = a >> 16;
	b += a;

	return b;
}

int main() {
	unsigned long long data;
	//unsigned long long goal = 0x123456789abcdef0;
	node ** heap;
	int n;
	node ** hash_table;
	int finished;
	int result;

	heap = (node **)malloc(sizeof(node *) * HEAP_SIZE + 1);
	for (int i = 1; i <= HEAP_SIZE; i++) {
		heap[i] = NULL;
	}
	n = 0;
	hash_table = (node **)malloc(sizeof(node *) * HASH_SIZE);
	for (int i = 0; i < HASH_SIZE; i++) {
		hash_table[i] = NULL;
	}

	data = 0;
	for (int i = 0; i < 16; i++) {
		unsigned int a;
		std::cin >> a;
		data = (data << 4) + a;
	}

	try
	{
		finished = create(data, 0, Mdistance(data), hash_table, heap, &n);
	}
	catch (...)
	{
		return 1;
	}
	if (finished) {
		std::printf("0\n");
		return 0;
	}

	finished = 0;
	while (1) {
		if (n == 0) {
			std::printf("empty heap\n");
			return 1;
		}

		node * p = heap[1];
		heap_delete(heap, &n, 1);

		unsigned long long new_data;
		int zero_index = find_zero(p->data);
		int dif_f = 0;

		if (zero_index % 4 != 3) {
			new_data = move_right(p->data, zero_index, &dif_f);
			try
			{
				finished += create(new_data, p->steps + 1, p->f + dif_f, hash_table, heap, &n);
			}
			catch (...)
			{
				return 1;
			}
		}
		if (zero_index % 4 != 0) {
			new_data = move_left(p->data, zero_index, &dif_f);
			try
			{
				finished += create(new_data, p->steps + 1, p->f + dif_f, hash_table, heap, &n);
			}
			catch (...)
			{
				return 1;
			}
		}
		if (zero_index < 12) {
			new_data = move_down(p->data, zero_index, &dif_f);
			try
			{
				finished += create(new_data, p->steps + 1, p->f + dif_f, hash_table, heap, &n);
			}
			catch (...)
			{
				return 1;
			}
		}
		if (zero_index > 3) {
			new_data = move_up(p->data, zero_index, &dif_f);
			try
			{
				finished += create(new_data, p->steps + 1, p->f + dif_f, hash_table, heap, &n);
			}
			catch (...)
			{
				return 1;
			}
		}

		if (finished) {
			result = p->steps + 1;
			break;
		}
	}

	std::printf("%d\n", result);

	return 0;
}