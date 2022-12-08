/*
 * Trabalho de Programação Paralela e Concorrente
 * Nome: Matheus Costa Granja
 * Matricula: 1426580
 */

#include "restroom.h"

Restroom::Restroom(int nBox){
	SetCurrentGender(0);
	SetNBox(nBox);
	busy = 0;
}

void Restroom::SetCurrentGender(int currentGender){
	this->currentGender = currentGender;
}

int Restroom::GetCurrentGender(){
	return currentGender;
}

void Restroom::SetNBox(int nBox){
	this->nBox = nBox;
}

int Restroom::GetNBox(){
	return nBox;
}

bool Restroom::OcuppyBox(){

	if( busy < nBox )
		busy++;
	else
		return false;
	return true;
}

void Restroom::VacateBox(){

	if( busy > 0 )
		busy--;
}

bool Restroom::Empty(){

	return ( busy == 0 )?(true):(false);
}