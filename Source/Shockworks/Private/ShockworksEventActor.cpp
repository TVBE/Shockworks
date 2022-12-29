// Fill out your copyright notice in the Description page of Project Settings.


#include "ShockworksEventActor.h"

// Sets default values
AShockworksEventActor::AShockworksEventActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShockworksEventActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShockworksEventActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

