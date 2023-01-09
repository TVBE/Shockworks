// Copyright 2023 Nino Saglia & Tim Verberne

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DetonationComponent.generated.h"

/** Actor Component that handles the source and reflections for a Detonation Event. This component will add two
 *  additional AudioComponents to its owner to play the respective audio from. */
UCLASS( ClassGroup=(Shockworks), meta=(BlueprintSpawnableComponent) )
class UDetonationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDetonationComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
