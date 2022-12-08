/*
 * Trabalho de Programação Paralela e Concorrente
 * Nome: Matheus Costa Granja
 * Matricula: 1426580
 */

#include <iostream>
#include <time.h>
#include <unistd.h>
#include "person.h"

Person::Person(int id, int gender){
	SetId(id);
	SetGender(gender);
}

void Person::SetId(int id){
	this->id = id;
}

int Person::GetId(){
	return id;
}

void Person::SetGender(int gender){
	this->gender = gender;
}

int Person::GetGender(){
	return gender;
}

bool Person::EnterRestroom(Restroom *restroom){
	
	if( !restroom->Empty() && restroom->GetCurrentGender() != gender )
		return false;

	else if( restroom->Empty() ){
		std::cout << "Vez do genero " << gender << "!" << std::endl;
		restroom->SetCurrentGender(gender);
	}
	return true;
}

void Person::GetStall(Restroom *restroom, clock_t *end, pthread_mutex_t *mutexGetBox, pthread_mutex_t *mutexLeaveBox){
	
	while( !restroom->OcuppyBox() );
	*end = clock();
	std::cout << id << " entrou no box! (Genero:" << gender << ")" << std::endl;
	pthread_mutex_unlock(mutexGetBox);
	sleep(5);
	pthread_mutex_lock(mutexLeaveBox);
	restroom->VacateBox();
	std::cout << id << " saiu do box! (Genero:" << gender << ")" << std::endl;
	pthread_mutex_unlock(mutexLeaveBox);
}