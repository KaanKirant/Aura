// Copyright Kaan Kirant


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"

AAuraPlayerController::AAuraPlayerController()
{
	//Replication is for multiplayer. It replicates the changes to other clients.
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//Assert has been used here to make sure player can move. If player cannot move the game should crash out.
	check(AuraContext);
	//Setting up the enhanced input system
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	//Crash if subsystem is null.
	check(Subsystem);
	//Adding aura mapping context to subsystem.
	Subsystem->AddMappingContext(AuraContext, 0);

	//Setting cursor details.
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
