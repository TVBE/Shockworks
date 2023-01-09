// Copyright 2023 Nino Saglia & Tim Verberne

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SoundmixModifierComponent.generated.h"

/** Actor Component that pushes Sound Mix Modifiers if a detonation is near the listener. */
UCLASS( ClassGroup=(Shockworks), meta=(BlueprintSpawnableComponent) )
class USoundmixModifierComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USoundmixModifierComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
