// Copyright 2023 Nino Saglia & Tim Verberne.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EventWorldData.h"
#include "ShockworksEventActor.generated.h"


/** Abstract superclass that all Shockworks event actor types derive from. Contains basic logic for triggering events and attaching
 *  the actor to other scene components. Handles object pool release when finished. */
UCLASS(Abstract, NotBlueprintable, BlueprintType, ClassGroup=(Shockworks))
class SHOCKWORKS_API AShockworksEventActor : public AActor
{
	GENERATED_BODY()
	
private:

	/** Struct containing information about the the actors location and relation to the listener. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = EventData, Meta = (AllowPrivateAccess = "true", DisplayName="Event World Data"))
	FEventWorldData EventWorldData;

public:	
	// Sets default values for this actor's properties
	AShockworksEventActor();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	/** Returns an FEventWorldData struct containing contextual information about the actors location in the world.
	 *  Is normally updated every time a new event is posted on this actor. */
	UFUNCTION(BlueprintCallable)
	FEventWorldData GetEventWorldData();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	/** Returns the obstruction amount for the event actor in relation to the listener. */
	float GetObstruction() const;

	/** Returns the enclosure amount for the event actor. */
	float GetEnclosure() const;

	/** Returns the distance between the event actor and the listener. */
	int GetDistanceToListener() const;

	/** Returns the delay for the event to be audible to the listener. */
	float GetDelayToListener() const;

	/** Generates a new FEventWorldData struct for the actors current location and relation to the listener.*/
	void GenerateEventWorldData();
};
