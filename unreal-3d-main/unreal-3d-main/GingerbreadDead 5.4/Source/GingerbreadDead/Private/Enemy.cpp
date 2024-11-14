// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "FlamethrowerCollisionActor.h"
#include "GingerbreadDead/GingerbreadDeadCharacter.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Hitbox = CreateDefaultSubobject<USphereComponent>(TEXT("Hitbox Component"));

	RootComponent = Hitbox;
	EnemyMesh->SetupAttachment(RootComponent);

}

int AEnemy::GetHealth()
{
	return Health;
}

void AEnemy::SetHealth(int HealthValue)
{
	Health = HealthValue;
}

void AEnemy::DealDamage(int DamageDealt)
{
	Health = Health - DamageDealt;

	if(Health <= 0)
	{
		this->Destroy();
	}
}

int AEnemy::GetDamage()
{
	return Damage;
}

void AEnemy::SetDamage(int DamageValue)
{
	Damage = DamageValue;
}

void AEnemy::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//check if the otheractor is the flamethrower collision actor
	AFlamethrowerCollisionActor* FlameCheck = Cast<AFlamethrowerCollisionActor>(OtherActor);
	if(FlameCheck)
	{
		UE_LOG(LogTemp, Warning, TEXT("Flame collided with enemy"));

		this->DealDamage(Player->GetUIManager()->GetCurrentDamage());

		if(Health <= 0)
		{
			Player->GetUIManager()->IncreaseHeat(30);
			this->Destroy();
		}
		
	}
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<AGingerbreadDeadCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

	Hitbox->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnBeginOverlap);
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

