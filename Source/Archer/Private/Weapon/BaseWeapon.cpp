// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/BaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"


ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMeshComponent");
	SetRootComponent(WeaponMeshComponent);
}


void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	check(WeaponMeshComponent);
	
}

void ABaseWeapon::Fire()
{
	MakeShot();
}


void ABaseWeapon::MakeShot()
{
	if(!GetWorld()) return;

	const auto Player = Cast<ACharacter>(GetOwner());
	
	if(!Player) return; 

	const auto Controller = Player->GetController<APlayerController>();
	
	if(!Controller) return;

	FVector ViewLocation;
	
	FRotator ViewRotation;

	Controller->GetPlayerViewPoint(ViewLocation, ViewRotation);

	const FTransform SocketTransform = WeaponMeshComponent->GetSocketTransform(ArrowSpawnSocketName);
	
	const FVector TraceStart = ViewLocation;
	
	const FVector ShootDirection = ViewRotation.Vector();
	
	const FVector TraceEnd = TraceStart + ShootDirection * TraceMaxDistance;
	
	FCollisionQueryParams CollisionParams;
	
	CollisionParams.AddIgnoredActor(GetOwner());

	FHitResult HitResult;
	
	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility);

	if(HitResult.bBlockingHit)
	{
		DrawDebugLine(GetWorld(), SocketTransform.GetLocation(), HitResult.ImpactPoint, FColor::Red, false, 3.0f, 0, 3.0f);
		
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 24, FColor::Green, false, 0.5f);
	}
	else
	{
		DrawDebugLine(GetWorld(), SocketTransform.GetLocation(), TraceEnd, FColor::Blue, false, 3.0f, 0, 3.0f);
	}
}


