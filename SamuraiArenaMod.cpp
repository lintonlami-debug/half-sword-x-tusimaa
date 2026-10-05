// SamuraiArenaMod.cpp
#include "SamuraiArenaMod.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

ASamuraiArenaMod::ASamuraiArenaMod()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ASamuraiArenaMod::BeginPlay()
{
    Super::BeginPlay();
}

void ASamuraiArenaMod::HandleWeaponCollision(
    AActor* Attacker,
    AActor* Defender,
    FVector ImpactPoint,
    FVector ImpactNormal)
{
    if (!Attacker || !Defender)
        return;

    FVector Direction = -ImpactNormal;

    // Physical reaction rather than graphic injury
    if (ACharacter* Character = Cast<ACharacter>(Defender))
    {
        Character->LaunchCharacter(
            Direction * WeaponImpactForce,
            true,
            false
        );

        ApplyStagger(Defender, Direction);
    }
}

void ASamuraiArenaMod::ApplyStagger(
    AActor* Defender,
    FVector Direction)
{
    if (ACharacter* Character = Cast<ACharacter>(Defender))
    {
        if (UCharacterMovementComponent* Movement =
            Character->GetCharacterMovement())
        {
            Movement->StopMovementImmediately();
        }

        // Hook your animation/state-machine stagger
        // into this point.
    }
}