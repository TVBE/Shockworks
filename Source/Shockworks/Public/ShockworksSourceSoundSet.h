// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ShockworksBifadeSoundSubset.h"
#include "ShockworksUnifadeSoundSubset.h"
#include "ShockworksSourceSoundset.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FShockworksSourceSoundset {
	GENERATED_USTRUCT_BODY()

	// Close
	/** The sounds to use when the event is close to the listener. Typically this is less than 2000 units. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Close)
	FShockworksUnifadeSoundSubset CloseLayer;

	// MediumClose
	/** The sounds to use when the event is medium-close to the listener. Typically this is within the range of 2000 to 3000 units. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = MediumClose)
	FShockworksBifadeSoundSubset MediumCloseLayer;

	// Medium
	/** The sounds to use when the event is medium far away from the listener. Typically this is within the range of 3000 to 5000 units. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Medium)
	FShockworksBifadeSoundSubset MediumLayer;

	// MediumFar
	/** The sounds to use when the event is medium far away from the listener. Typically this is within the range of 5000 to 10000 units. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = MediumFar)
	FShockworksBifadeSoundSubset MediumFarLayer;

	// Distant
	/** The sounds to use when the event is far away from the listener. Typically this is more than 10000 units. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Distant)
	FShockworksUnifadeSoundSubset DistantLayer;



	// Constructor with default values.
	FShockworksSourceSoundset()
	{
		CloseLayer = FShockworksUnifadeSoundSubset(FVector2D(1000, 2000));
		MediumCloseLayer = FShockworksBifadeSoundSubset(FVector2D(1000, 2000), FVector2D(2000, 3250));
		MediumLayer = FShockworksBifadeSoundSubset(FVector2D(2000, 3250), FVector2D(3250, 8000));
		MediumFarLayer = FShockworksBifadeSoundSubset(FVector2D(3250, 5000), FVector2D(8000, 16000));
		DistantLayer = FShockworksUnifadeSoundSubset(FVector2D(8000, 16000));
	}
};
