// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ShockworksDetonationType.h"
#include "ShockworksDetonationEvent.generated.h"

/**
 * 
 */
UCLASS()
class SHOCKWORKS_API UShockworksDetonationEvent : public UDataAsset
{
	GENERATED_BODY()

public:

	// Detonation type
	/** The detonation type for this event. High explosives detonate at a rate greater than the speed of sound whereas low explosives deflagrate. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = EventData)
	TEnumAsByte <EShockworksDetonationType> DetonationType;

	// Force
	/** the force of the detonation. Higher values will cause the explosion to be louder and more aggresive. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = EventData, Meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	float Force = 25.0;

	// Shrapnel
	/** the amount of shrapnel that this explosion generates. This setting will incur a slight performance cost at higher values. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = EventData, Meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	float Shrapnel = 25.0;

	// Debris
	/** the amount of debris that this explosion generates. This setting will incur a slight performance cost at higher values. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = EventData, Meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	float Debris = 25.0;

	// Tone
	/** Alters the character of the event. Lower values will make the event more bottom heavy and drawn out, while higher values will make the event more harsh and spikey. Leave at 50 for default. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Character, Meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	float Tone = 50.0;

	// Impact
	/** Alters the impact of the event. Higher values will add more punch to the event. Leave at 50 for default. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Character, Meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	float Impact = 50.0;
};
