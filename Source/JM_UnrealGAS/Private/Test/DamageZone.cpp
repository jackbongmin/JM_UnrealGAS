// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/DamageZone.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

// Sets default values
ADamageZone::ADamageZone()
{
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ADamageZone::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ADamageZone::OnBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &ADamageZone::OnEndOverlap);
}

void ADamageZone::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor);
	if (ASC)
	{
		FGameplayEffectContextHandle ConText = ASC->MakeEffectContext();
	}
}

void ADamageZone::OnEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
}
