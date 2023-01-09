// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundWave.h"
#include "Sound/SoundConcurrency.h"
#include "Sound/SoundAttenuation.h"

#include "PhysicsHitAudioData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FPhysicsHitAudioData
{
	GENERATED_USTRUCT_BODY()


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = PhysicsHitAudioData)
	FName Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = PhysicsHitAudioData, Meta = (ClampMin = "0.0", ClampMax = "10.0", UIMin = "0.0", UIMax = "10.0"))
	float Gain;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = PhysicsHitAudioData)
	float MaxSpeedScalar;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = PhysicsHitAudioData)
	float ImpulseLength;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Analysis)
	TArray<float> OnsetTimingData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Analysis)
	TMap<float, float> OnsetDataMap;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Analysis)
	TArray<float> OnsetVolumeData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Sounds)
	USoundWave* ImpactWaveAsset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Sounds)
	USoundWave* SlidingWaveAsset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Surface)
	TEnumAsByte<EPhysicalSurface> SurfaceType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Surface)
	bool IsStaticSurface;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Surface, Meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	float SurfaceDampeningPercentage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = AudioData)
	USoundAttenuation* Attenuation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = AudioData)
	USoundConcurrency* Concurrency;

	// Constructor with default values.
	FPhysicsHitAudioData()
	{
		Gain = 1.0;
		MaxSpeedScalar = 1.0;
		ImpulseLength = 1.0;
		IsStaticSurface = true;
		SurfaceDampeningPercentage = 25.0;
	}






};
