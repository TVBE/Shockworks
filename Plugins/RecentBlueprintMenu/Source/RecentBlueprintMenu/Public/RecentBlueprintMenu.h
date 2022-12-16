// Copyright 2022 The Tool Shed (Chris Garnier)

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FMenuBuilder;
class FExtender;

class FRecentBlueprintMenuModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	private:
    	//Delegate to generate new menu in BP
    	void OnBuildBlueprintMenu(FMenuBuilder&);
    
    	//Delegate to generate new menu in BP
    	void OnBuildRecentSubMenu(FMenuBuilder&);
    	
    	//Pointer to the extender used for the new custom blueprint menu
    	TSharedPtr<FExtender> BlueprintMenuExtender;
};
