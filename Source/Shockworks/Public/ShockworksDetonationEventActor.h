// Copyright 2023 Nino Saglia & Tim Verberne

#pragma once

#include "CoreMinimal.h"
#include "ShockworksEventActor.h"

#include "ShockworksDetonationEventActor.generated.h"

/** Event Actor that handles detonation events in the world. Derives from ShockworksEventActor. */
UCLASS(Blueprintable, BlueprintType)
class SHOCKWORKS_API AShockworksDetonationEventActor : public AShockworksEventActor
{
	GENERATED_BODY()

private:
	/** Component handling the detonation source audio and reflections. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, Meta = (AllowPrivateAccess = "true", DisplayName="Detonation Component"))
	class UDetonationComponent* DetonationComponent;

	/** Component handling the audio of detonation fragments hitting the surrounding area and whizzing by the listener. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, Meta = (AllowPrivateAccess = "true", DisplayName="Fragmentation Component"))
	class UFragmentationComponent* FragmentationComponent;

	/** Component handling debris audio after the detonation. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, Meta = (AllowPrivateAccess = "true", DisplayName="Debris Component"))
	class UDebrisComponent* DebrisComponent;

	/** The Shockworks Detonation Event that is assigned to this actor. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Actor, Meta = (AllowPrivateAccess = "true", DisplayName="Shockworks Detonation Event"))
	class UShockworksDetonationEvent* Event;
	
public:

	/** Returns DetonationComponent subobject. */
	FORCEINLINE UDetonationComponent* GetDetonationComponent() const { return DetonationComponent; }

	/** Returns FragmentationComponent subobject. */
	FORCEINLINE UFragmentationComponent* GetFragmentationComponent() const { return FragmentationComponent; }

	/** Returns DebrisComponent subobject. */
	FORCEINLINE UDebrisComponent* GetDebrisComponent() const { return DebrisComponent; }

	/** Returns currently assigned Detonation Event. */
	FORCEINLINE UShockworksDetonationEvent* GetEvent() const { return Event; }
	
public:

	// Sets default values for this actor's properties
	AShockworksDetonationEventActor();
};
