// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundWave.h"
#include "ShockworksBifadeSoundSubset.generated.h"

/**
 * 
 */
 
USTRUCT(BlueprintType)
struct FShockworksBifadeSoundSubset;
{
	GENERATED_USTRUCT_BODY()

	// LayerA Files
	/** An array of WaveFiles to be passed to the MetaSound instance. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Soundset)
	TArray<USoundWave*> LayerAFiles;

	// Layer B Files
	/** An array of WaveFiles to be passed to the MetaSound instance. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Soundset)
	TArray<USoundWave*> LayerBFiles;

	// Fade-in range
	/** Defines the fade-in range for this subset.  */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Soundset)
	FVector2D FadeInRange;

	// Fade-out range
	/** Defines the fade-out range for this subset. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Soundset)
	FVector2D FadeOutRange;

	/** Constructor with default values. */
	FShockworksBifadeSoundSubset()
	{
		FadeInRange = FVector2d();
		FadeOutRange = FVector2d();
	}

	/** Constructor which allows us to set the fade ranges. */
	FShockworksBifadeSoundSubset(FVector2D const InRange, FVector2D const OutRange)
	{
		FadeInRange = InRange;
		FadeOutRange = OutRange;
	}
};
