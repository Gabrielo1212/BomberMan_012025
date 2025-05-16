// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueConcreto.h"

void ABloqueConcreto::ActivarMovimiento_Implementation(){
    if(PuedeMoverse==false){
        PuedeMoverse=true;
    }else{
        PuedeMoverse=false;
    }
}
