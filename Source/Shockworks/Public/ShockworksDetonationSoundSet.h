// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ShockworksSoundsetEntry.h"
#include "ShockworksDetonationSoundSet.generated.h"

/**
 * 
 */
UCLASS()
class SHOCKWORKS_API UShockworksDetonationSoundSet : public UDataAsset
{
	GENERATED_BODY()

public:

	// Close
	/** The sounds to use when the event is close to the listener. Typically this is less than 2000 units. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Close)
	FShockworksSoundsetEntry CloseLayer;

	// MediumClose
	/** The sounds to use when the event is medium-close to the listener. Typically this is within the range of 2000 to 3000 units. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = MediumClose)
	FShockworksSoundsetEntry MediumCloseLayer;

	// Medium
	/** The sounds to use when the event is medium far away from the listener. Typically this is within the range of 3000 to 5000 units. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Medium)
	FShockworksSoundsetEntry MediumLayer;

	// MediumFar
	/** The sounds to use when the event is medium far away from the listener. Typically this is within the range of 5000 to 10000 units. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = MediumFar)
	FShockworksSoundsetEntry MediumFarLayer;

	// Distant
	/** The sounds to use when the event is far away from the listener. Typically this is more than 10000 units. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Distant)
	FShockworksSoundsetEntry DistantLayer;

};
