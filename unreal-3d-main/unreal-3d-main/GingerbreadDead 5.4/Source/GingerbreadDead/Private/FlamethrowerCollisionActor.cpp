// Fill out your copyright notice in the Description page of Project Settings.


#include "FlamethrowerCollisionActor.h"

#include "Components/SphereComponent.h"
#include "GingerbreadDead/GingerbreadDeadCharacter.h"

// Sets default values
AFlamethrowerCollisionActor::AFlamethrowerCollisionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Hitbox = CreateDefaultSubobject<USphereComponent>(TEXT("Hitbox Component"));
	RootComponent = Hitbox;

}

/*void AFlamethrowerCollisionActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AGingerbreadDeadCharacter* PlayerCheck = Cast<AGingerbreadDeadCharacter>(OtherActor);
	if(PlayerCheck)
	{
		//PlayerCheck->HeldWeapon->
		UE_LOG(LogTemp, Warning, TEXT("Player collided with flame hehe"));
	}
}*/

// Called when the game starts or when spawned
void AFlamethrowerCollisionActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFlamethrowerCollisionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

