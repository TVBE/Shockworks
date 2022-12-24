// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhysicsHitAudioData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FphysicsHitAudioData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = 'PhysicsHitAudioData')
	float Gain;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = 'PhysicsHitAudioData')
	EphysicalMaterial

};
