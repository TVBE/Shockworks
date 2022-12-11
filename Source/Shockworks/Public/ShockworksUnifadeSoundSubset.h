// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundWave.h"
#include "FShockworksUnifadeSoundSubset.generated.h"

/**
 *
 */

USTRUCT(BlueprintType)
struct FShockworksUnifadeSoundSubset{
	GENERATED_USTRUCT_BODY()

	// LayerA Files
	/** An array of WaveFiles to be passed to the MetaSound instance. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Soundset)
	TArray<USoundWave*> LayerAFiles;

	// Layer B Files
	/** An array of WaveFiles to be passed to the MetaSound instance. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Soundset)
	TArray<USoundWave*> LayerBFiles;

	// Fade range
	/** Defines the fade range for this subset.  */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Soundset)
	FVector2D FadeRange;

	

	/** Constructor with default values. */
	FShockworksUnifadeSoundSubset()
	{
		FadeRange = FVector2d();
	}

	/** Constructor which allows us to set the fade ranges. */
	FShockworksUnifadeSoundSubset(FVector2D const Range)
	{
		FadeRange = Range;
	}
};
