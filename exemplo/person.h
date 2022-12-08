/*
 * Trabalho de Programação Paralela e Concorrente
 * Nome: Matheus Costa Granja
 * Matricula: 1426580
 */

#ifndef PERSON_H
#define PERSON_H

#include "restroom.h"

class Person{
	public:
		Person(int id, int gender);

		void SetId(int id);
		int GetId();

		void SetGender(int gender);
		int GetGender();

		bool EnterRestroom(Restroom *restroom);
		void GetStall(Restroom *restroom, clock_t *end, pthread_mutex_t *mutexGetBox, pthread_mutex_t *mutexLeaveBox);

	private:
		int id;
		int gender;
};

#endif