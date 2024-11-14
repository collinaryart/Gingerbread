// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FlamethrowerCollisionActor.h"
#include "ItemComponent.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraDataInterfaceExport.h"
#include "UIManager.h"
#include "GingerbreadDeadCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AGingerbreadDeadCharacter : public ACharacter, public INiagaraParticleCallbackHandler
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere)
	UNiagaraSystem* NS_Flame;

	FVector FlameOffset = FVector(0,0,-75); // makes sure effect spawns in the centre of capsule

	UPROPERTY(EditAnywhere)
	TSubclassOf<AFlamethrowerCollisionActor> FlameCollisionClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AUIManager> UIManagerClass; // Needs to be populated somehow (e.g. by exposing to blueprints as uproperty and setting it there

	

	
public:
	AGingerbreadDeadCharacter();

	UItemComponent* HeldWeapon;
	

	UPROPERTY(EditAnywhere)
		UInputAction* ShootHoldAction;

	void UseWeapon();

	virtual void ReceiveParticleData_Implementation(const TArray<FBasicParticleData>& Data, UNiagaraSystem* NiagaraSystem, const FVector& SimulationPositionOffset) override;

	AUIManager* UIManager;

	AUIManager* GetUIManager();
protected:
	virtual void BeginPlay();

public:

    UPROPERTY(EditAnywhere)
		UAudioComponent* AudioComponent;

	bool bisFootstepsPlaying;
	void StartFootsteps();
	void ResetFootsteps();
	
	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	/** Bool for AnimBP to switch to another animation set */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Weapon)
	bool bHasRifle;

	/** Setter to set the bool */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void SetHasRifle(bool bNewHasRifle);

	/** Getter for the bool */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	bool GetHasRifle();

	UFUNCTION(NetMulticast, Reliable)
	void Flames(); // spawns flame particle effect

protected:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

public:
	/** Returns Mesh1P subobject **/
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

};

