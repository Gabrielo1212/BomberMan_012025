// Fill out your copyright notice in the Description page of Project Settings.


#include "PrimerEstadoDeJuego.h"

APrimerEstadoDeJuego::APrimerEstadoDeJuego()
{
CurrentScore = 0;
}
int32 APrimerEstadoDeJuego::GetScore()
{
return CurrentScore;
}
void APrimerEstadoDeJuego::SetScore(uint32 NewScore)
{
CurrentScore = NewScore;
}
