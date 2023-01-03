// Copyright 2023 Nino Saglia & Tim Verberne


#include "ShockworksDetonationEventActor.h"
#include "DetonationComponent.h"
#include "FragmentationComponent.h"
#include "DebrisComponent.h"
#include "SoundmixModifierComponent.h"

// Sets the default values.
AShockworksDetonationEventActor::AShockworksDetonationEventActor()
{
	PrimaryActorTick.bCanEverTick = true;

	/** Create components. */
	DetonationComponent = CreateDefaultSubobject<UDetonationComponent>(TEXT("DetonationComponent"));
	FragmentationComponent = CreateDefaultSubobject<UFragmentationComponent>(TEXT("FragmentationComponent"));
	DebrisComponent = CreateDefaultSubobject<UDebrisComponent>(TEXT("DebrisComponent"));
	// SoundmixModifierComponent = CreateDefaultSubobject<USoundmixModifierComponent>(TEXT("SoundMixModifierComponent"));
}




