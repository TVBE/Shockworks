// Copyright 2022 The Tool Shed (Chris Garnier)

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RecentBlueprintMenuSettings.generated.h"

/**
 * Settings class for RecentBlueprintMenu to save recent BPs and other info
 */
UCLASS(config=EditorPerProjectUserSettings)
class RECENTBLUEPRINTMENU_API URecentBlueprintMenuSettings : public UObject
{
	GENERATED_BODY()

public:
	//List of blueprints that were recently open to show in the Recent menu
	UPROPERTY(Config)
	TArray<FString> RecentBlueprints;

	//How many Blueprints to remember max
	UPROPERTY(Config) //not presented in a menu but users can modify in ini
	uint8 MaxRecentBP = 15;
};
