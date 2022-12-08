/*
 * Trabalho de Programação Paralela e Concorrente
 * Nome: Matheus Costa Granja
 * Matricula: 1426580
 */

#include <vector>
#include <pthread.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "restroom.h"
#include "person.h"

#define N_GENDER 3
#define N_PERSON 300 // 60 150 300
#define N_BOX 5     //  1   3   5

Restroom restroom(N_BOX); // Banheiro
std::vector<int> queue; // Fila
int *count_person; // Vetor com numero restante de "vagas" em cada genero
int *waiting_time; // Tempo de espera por genero
pthread_t *thread_person; // Threads
pthread_mutex_t mutexEnter;
pthread_mutex_t mutexLeaveBox;

void PrintQueue(){
	std::cout << "Fila: ";
	for( int i=0; i<queue.size(); i++ )
		std::cout << queue[i] << " ";
	std::cout << std::endl;
}

void *FuncPerson(void *idThread){

	long id = (long)idThread;
	int gender = -1;
	clock_t start, end;

	do{
		gender = rand()%N_GENDER;

		if( count_person[gender] > 0 )
			count_person[gender]--;
		
		else
			gender = -1;

	}while( gender == -1 );

	start = clock();
	Person person(id, gender);
	std::cout << person.GetId() << " entrou na fila! (Genero: " << person.GetGender() << ")" << std::endl;
	PrintQueue();

	while( person.GetId() != queue[0] ); // Aguarda ser o primeiro da fila

	pthread_mutex_lock(&mutexEnter);
	while( !person.EnterRestroom(&restroom) );
	queue.erase(queue.begin()); // Sai da fila
	std::cout << person.GetId() << " saiu da fila! (Genero: " << person.GetGender() << ")" << std::endl;
	PrintQueue();
	person.GetStall(&restroom, &end, &mutexEnter, &mutexLeaveBox);

	waiting_time[person.GetGender()] += (end - start)/CLOCKS_PER_SEC;
}

int main(){

	count_person = new int[N_GENDER];
	waiting_time = new int[N_GENDER];
	thread_person = new pthread_t[N_PERSON];
	pthread_mutex_init(&mutexEnter, NULL);
	pthread_mutex_init(&mutexLeaveBox, NULL);
	clock_t start, end;
	int total_time;

	srand(time(NULL));

	for( int i=0; i<N_GENDER; i++ ){
		count_person[i] = N_PERSON/N_GENDER;
		waiting_time[i] = 0;
	}

	start = clock();
	for( int i=0; i<N_PERSON; i++ ){

		queue.push_back(i);

		pthread_create(&thread_person[i], NULL, FuncPerson, (void *)i);

		sleep((rand()%7)+1);
	}

	for( int i=0; i<N_PERSON; i++ )
		pthread_join(thread_person[i], NULL);
	end = clock();

	total_time = (end - start)/CLOCKS_PER_SEC;

	std::cout << std::endl;
	std::cout << "Total de pessoas: " << N_PERSON << std::endl;
	std::cout << "Total de boxes: " << N_BOX << std::endl;
	std::cout << "Tempo total: " << total_time/60 << " minutos e " << total_time - (total_time/60)*60 << " segundos" << std::endl;
	std::cout << "Quantidade de pessoas por genero: " << N_PERSON/N_GENDER << std::endl;
	std::cout << "Tempo de espera por genero:" << std::endl;
	for( int i=0; i<N_GENDER; i++ ){
		std::cout << " | " << i << ": " << waiting_time[i] << " segundos no total ";
		std::cout << "(cerca de " << (waiting_time[i]*1.0/(N_PERSON/N_GENDER)) << " segundos por pessoa)" << std::endl;
	}
	std::cout << "Taxa de ocupacao do box: " << (5.0*N_PERSON)/(total_time*N_BOX) << std::endl;

	delete[] count_person;
	delete[] thread_person;
	pthread_mutex_destroy(&mutexEnter);
	pthread_mutex_destroy(&mutexLeaveBox);
    pthread_exit(NULL);
}