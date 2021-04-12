// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/StaticMeshComponent.h"
#include "Dummie.h"
#include "TS_GABRIEL_CABRERACharacter.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	staticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("staticMeshComponent"));
	staticMeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	staticMeshComponent->GetSocketLocation("Muzzle");
	current_Ammo = max_Ammo;
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::Shoot_Implementation()
{
	
	if (bCanShoot)
	{
		TArray<UActorComponent*> scenescomponents = GetComponentsByTag(USceneComponent::StaticClass(), "Muzzle");
		USceneComponent* muzzle = Cast<USceneComponent>(scenescomponents[0]);
		FHitResult* outhit = new FHitResult();

		FVector start = muzzle->GetComponentLocation();
		FCollisionQueryParams* collisionParams = new FCollisionQueryParams();
		DrawDebugLine(GetWorld(), start, end, FColor::Green, false, 1, 0, 1);

		if (GetWorld()->LineTraceSingleByChannel(*outhit, start, end, ECC_Visibility, *collisionParams))
		{
			if (ADummie* dummie=Cast<ADummie>(outhit->Actor))
			{
				dummie->bIsHit = true;
				dummie->SetRotation(90.f);
				ATS_GABRIEL_CABRERACharacter* player =Cast<ATS_GABRIEL_CABRERACharacter>( GetGameInstance()->GetPrimaryPlayerController()->GetCharacter());
				player->deaths++;
			}
		}

		FTimerDelegate TimerDel;
		TimerDel.BindUFunction(this, FName("SetbCanShoot"), true);
		GetWorldTimerManager().SetTimer(FuzeTimerHandle, TimerDel, cooldown, false);
		current_Ammo--;
	}

	

}

void AGun::SetbCanShoot(bool b)
{
	bCanShoot = b;
	GetWorldTimerManager().ClearTimer(FuzeTimerHandle);
}