// Copyright 2023 Nino Saglia & Tim Verberne

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DebrisComponent.generated.h"

/** Actor Component that handles debris audio after a detonation. */
UCLASS( ClassGroup=(Shockworks), meta=(BlueprintSpawnableComponent) )
class UDebrisComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDebrisComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
