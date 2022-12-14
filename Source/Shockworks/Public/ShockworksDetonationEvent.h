// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ShockworksDetonationEvent.generated.h"



/**
 * 
 */
UCLASS(BlueprintType)
class SHOCKWORKS_API UShockworksDetonationEvent : public UDataAsset
{
	GENERATED_BODY()

public:

	// Detonation type
	/** The detonation type for this event. */
	// UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Soundset)
	// UShockworksDetonationSoundset* DetonationSoundset;

	// Shrapnel
	/** the amount of shrapnel that this explosion generates. This setting will incur a slight performance cost at higher values. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = EventData, Meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	float Shrapnel = 25.0;

	// Debris
	/** the amount of debris that this explosion generates. This setting will incur a slight performance cost at higher values. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = EventData, Meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	float Debris = 25.0;

	// Shellshock
	/** Defines the amount of shellshock effect that the listener should experience when within the radius of the explosion. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Shellshock, Meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	float Shellshock = 0.0;

	// Max Shellshock Radius
	/** Defines the range at which the maximum amount of shellshock is applied to the listener.*/
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Shellshock)
	float MaxShellshockRadius = 300;

	// Min Shellshock Radius
	/** Defines the outer radius at which point no shellshock is applied to the listener anymore. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Shellshock)
	float MinShellshockRadius = 1000;
};
