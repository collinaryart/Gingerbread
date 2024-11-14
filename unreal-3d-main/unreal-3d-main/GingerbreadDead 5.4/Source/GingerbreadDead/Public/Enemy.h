// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Enemy.generated.h"

class AGingerbreadDeadCharacter;

UCLASS()
class GINGERBREADDEAD_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

	AGingerbreadDeadCharacter* Player;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* EnemyMesh;

	UPROPERTY(EditAnywhere)
	USphereComponent* Hitbox;

	int Health = 30;
	int Damage = 2;

	int GetHealth();
	void SetHealth(int HealthValue);

	void DealDamage(int DamageDealt);

	int GetDamage();
	void SetDamage(int DamageValue);

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
