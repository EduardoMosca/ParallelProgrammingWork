/*
 * Trabalho de Programação Paralela e Concorrente
 * Nome: Matheus Costa Granja
 * Matricula: 1426580
 */

#ifndef RESTROOM_H
#define RESTROOM_H

class Restroom{
	public:
		Restroom(int nBox);

		void SetCurrentGender(int currentGender);
		int GetCurrentGender();

		void SetNBox(int nBox);
		int GetNBox();

		bool OcuppyBox();
		void VacateBox();

		bool Empty();

	private:
		int currentGender;
		int nBox;
		int busy;
};

#endif