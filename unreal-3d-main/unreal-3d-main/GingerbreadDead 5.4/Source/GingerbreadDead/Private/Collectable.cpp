// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectable.h"

#include "GingerbreadDead/GingerbreadDeadCharacter.h"

// Sets default values
ACollectable::ACollectable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Hitbox = CreateDefaultSubobject<USphereComponent>(TEXT("Hitbox Component"));
	ItemComponent = CreateDefaultSubobject<UItemComponent>(TEXT("Item Component"));
	RootComponent = Hitbox;
	ItemComponent->SetupAttachment(RootComponent);
	
}

void ACollectable::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AGingerbreadDeadCharacter* Player = Cast<AGingerbreadDeadCharacter>(OtherActor);

	if(Player)
	{
		//if not already holding a weapon, delete this actor and attach it's component to the player
		if(!Player->HeldWeapon)
		{
			Hitbox->OnComponentBeginOverlap.RemoveAll(this);
			ItemComponent->Attach(Player);
		}
	}
}

// Called when the game starts or when spawned
void ACollectable::BeginPlay()
{
	Super::BeginPlay();

	Hitbox->OnComponentBeginOverlap.AddDynamic(this, &ACollectable::OnBeginOverlap);
	
}

// Called every frame
void ACollectable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

