// Copyright 2023 Nino Saglia & Tim Verberne

#pragma once

#include "CoreMinimal.h"
#include "EventWorldData.generated.h"


/** Struct that contains data about a Shockworks event's world location and context in relation to the listener.
 *  This data is calculated and passed to observers via the BEGIN EVENT delegate whenever a event is triggered in an ShockworksDetonationEventActor instance. */
USTRUCT(BlueprintType)
struct FEventWorldData
{
	GENERATED_USTRUCT_BODY()
	
	/** When set to true, this event is assumed to be static. This allows observers to perform certain calculations only once instead of updating per frame. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = General)
	bool IsStatic;
	
	/** The amount that the event is enclosed by geometry. This value allows us to scale interior reverb down when the event is triggered inside a partially open building. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Location, Meta = (ClampMin = 0.0, ClampMax = 1.0, UIMin = 0.0, UIMax = 1.0))
	float Enclosure;
	
	/** The distance between the event and the listener in units. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Distance)
	int DistanceToListener;

	/** The time for the sound waves of the event to travel to the listener, multiplied by a global 'speed of sound' multiplier. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Distance, meta = (ClampMin = 0.0))
	float DelayToListener;

	/** The amount of obstruction between the event and the listener. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Obstruction, meta = (ClampMin = 0.0, ClampMax = 1.0, UIMin = 0.0, UIMax = 1.0))
	float Obstruction;	



	/** Constructor with default values. */
	FEventWorldData()
	{
		IsStatic = true;
		Enclosure = 0.0;
		DistanceToListener = 0;
		DelayToListener = 0.0;
		Obstruction = 0.0;
	}
};