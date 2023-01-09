// Copyright 2023 Nino Saglia & Tim Verberne.


#include "ShockworksEventActor.h"
#include "Engine/World.h"

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

/** Calculates the distance between the actor and the listener. */
int AShockworksEventActor::GetDistanceToListener() const
{
	int Distance {0};
	if (IsValid(GetWorld()->GetFirstPlayerController()->PlayerCameraManager))
	{
		Distance = FVector::Dist((GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetCameraLocation()), GetActorLocation());
	}
	return Distance;
}

/** Calculates the distance delay between the actor and listener. Will set the delay to zero under a certain distance threshold
 *  to prevent very short delays being perceived as bad audio synchronisation by the user. */
float AShockworksEventActor::GetDelayToListener() const
{
	int Distance = GetDistanceToListener();
	float Delay {0.0};
	if (Distance >= 5000)
	{
		int SpeedOfSound {343}; // Real world speed of sound is 343 meters per second.
		Delay = (Distance * 0.01) / SpeedOfSound;
	}
	return Delay;
}

/** Calculates the enclosure of geometry around the event and the listener by performing multiple line traces.
 *  We can assume that some of the line traces will always return a hit result when the event is played on a surface,
 *  therefore we enforce a threshold of trace results before we start counting them as enclosure. */
float AShockworksEventActor::GetEnclosure() const
{
	return 0.0;
}


/** Calculates the obstruction of geometry between the event and the listener by performing multiple line traces.
 *  We can assume that some of the line traces will always return a hit result when the listener is located on a surface,
 *  therefore we enforce a threshold of trace results before we start counting them as obstruction. */
float AShockworksEventActor::GetObstruction() const
{
	float Obstruction {0.0};
	if (IsValid(GetWorld()->GetFirstPlayerController()->PlayerCameraManager))
	{
		int OffsetIncrement {350};
		int VerticalOffset {-OffsetIncrement};
		for (int i {0}; i < 3; i++ )
		{
			int HorizontalOffset {-OffsetIncrement};
			for (int j {0}; j < 3; j++)
			{
				FHitResult Hit;
				FCollisionQueryParams QueryParams;
				QueryParams.AddIgnoredActor(this);
				QueryParams.AddIgnoredActor(GetWorld()->GetFirstPlayerController()->GetPawn());
				
			}
		}
		
	}
	return Obstruction;
}


/** Called when a new event is assigned to the actor.*/
void AShockworksEventActor::GenerateEventWorldData()
{
	FEventWorldData EventData = FEventWorldData();
	EventData.DistanceToListener = GetDistanceToListener();
	EventData.DelayToListener = GetDelayToListener();
	EventData.Enclosure = GetEnclosure();
	EventData.Obstruction = GetObstruction();

	EventWorldData = EventData;
}

/** Returns the most recently generated EventWorldData struct. */
FEventWorldData AShockworksEventActor::GetEventWorldData()
{
	return EventWorldData;
}





