// Copyright 2023 Nino Saglia & Tim Verberne.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EventActor.generated.h"

/** Abstract superclass that all Shockworks event actor types derive from. Contains basic logic for triggering events and attaching
 *  the actor to other scene components. Handles object pool release when finished. */
UCLASS(Blueprintable, Abstract)
class SHOCKWORKS_API AEventActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEventActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
