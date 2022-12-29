// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PhysicsHitAudioData.h"
#include "PhysicsHitAudioDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class SHOCKWORKS_API UPhysicsHitAudioDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = PhysicsAudioData)
	TArray<FPhysicsHitAudioData> AudioData;
	
};
