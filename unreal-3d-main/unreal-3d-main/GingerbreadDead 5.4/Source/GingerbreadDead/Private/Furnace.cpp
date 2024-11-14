// Fill out your copyright notice in the Description page of Project Settings.


#include "Furnace.h"

#include "FlamethrowerCollisionActor.h"
#include "GingerbreadDead/GingerbreadDeadCharacter.h"

// Sets default values
AFurnace::AFurnace()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FurnaceMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Hitbox = CreateDefaultSubobject<USphereComponent>(TEXT("Hitbox Component"));

	RootComponent = Hitbox;
	FurnaceMesh->SetupAttachment(RootComponent);
	

}

int AFurnace::GetHealth()
{
	return Health;
}

void AFurnace::SetHealth(int HealthValue)
{
	Health = HealthValue;
}

void AFurnace::DealDamage(int DamageDealt)
{
	Health = Health - DamageDealt;

	if(Health <= 0)
	{
		this->Destroy();
	}
}

int AFurnace::GetDamage()
{
	return Damage;
}

void AFurnace::SetDamage(int DamageValue)
{
	Damage = DamageValue;
}

void AFurnace::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//check if the otheractor is the flamethrower collision actor
	AFlamethrowerCollisionActor* FlameCheck = Cast<AFlamethrowerCollisionActor>(OtherActor);
	if(FlameCheck)
	{
		//PlayerCheck->HeldWeapon->
		UE_LOG(LogTemp, Warning, TEXT("Flame collided with furnace"));

		Player->GetUIManager()->IncreaseHeat(1);

		this->DealDamage(1);

		if(Health <= 0)
		{
			Player->GetUIManager()->IncreaseHeat(100);
			this->Destroy();
		}
	}
	
	/*AGingerbreadDeadCharacter* PlayerCheck = Cast<AGingerbreadDeadCharacter>(OtherActor);
	if(PlayerCheck)
	{
		//PlayerCheck->HeldWeapon->
		UE_LOG(LogTemp, Warning, TEXT("Player collided with furnace"));
	}*/
}

// Called when the game starts or when spawned
void AFurnace::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<AGingerbreadDeadCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

	Hitbox->OnComponentBeginOverlap.AddDynamic(this, &AFurnace::OnBeginOverlap);
}

// Called every frame
void AFurnace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

