// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShockworksDetonationType.h"
#include "ShockworksSourceSoundSet.h"

#include "ShockworksDetonationSoundset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class SHOCKWORKS_API UShockworksDetonationSoundset : public UDataAsset
{
	GENERATED_BODY()

public:

	// Source Soundset
	/** The detonation source soundset to use for this event. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = EventData)
	FShockworksSourceSoundset Source = FShockworksSourceSoundset();

};
