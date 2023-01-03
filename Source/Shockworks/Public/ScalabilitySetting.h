// Copyright 2023 Nino Saglia & Tim Verberne

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ScalabilitySetting.generated.h"

/** Data asset for storing scalability settings for the Shockworks subsystem. This allows users to create different configurations
 *  for every target platform or quality setting. */
UCLASS(BlueprintType)
class SHOCKWORKS_API UShockworksScalabilitySetting : public UDataAsset
{
	GENERATED_BODY()

public:

	// General ---------------------------------------------------------------------------------------------------------

	/** Define the threshold for when Shockworks events will try to play detail effects such as shrapnel and debris. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = General)
	float DetailEffectThreshold = 7500.0;

	/** Define a global limit for the amount of Shockworks events that are allowed to play simultaneously. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = General)
	int Concurrency = 16;

	// Shrapnel --------------------------------------------------------------------------------------------------------

	/** When set to enabled, shrapnel effects are allowed to play. If you don't need any shrapnel effects, disable this to safe some performance overhead. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Shrapnel)
	bool AllowShrapnel = true;

	/** Define a global multiplier for the amount of shrapnel effects to play for each event. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Shrapnel, Meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float ShrapnelMultiplier = 1.0;

	/** Define an override for the shrapnel synthesis method. */
	// TODO: implement this


	// Debris ----------------------------------------------------------------------------------------------------------
	
	/** When set to enabled, Debris effects are allowed to play. If you don't need any shrapnel effects, disable this to safe some performance overhead. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Debris)
	bool AllowDebris = true;

	/** Define a global multiplier for the amount of Debris effects to play for each event. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Debris, Meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float DebrisMultiplier = 1.0;

	/** Define an override for the debris synthesis method. */
	// TODO: implement this
	
};
