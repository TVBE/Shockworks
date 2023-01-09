// Copyright 2023 Nino Saglia & Tim Verberne


#include "DetonationComponent.h"

// Sets default values for this component's properties
UDetonationComponent::UDetonationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDetonationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDetonationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

