// Copyright Kaan Kirant

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraEffectActor();

protected:
	virtual void BeginPlay() override;
    
    UPROPERTY(BlueprintCallable)
	void ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClas);

	UPROPERTY(EditAnywhere, Category= "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
};
