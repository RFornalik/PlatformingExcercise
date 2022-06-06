// Fill out your copyright notice in the Description page of Project Settings.


#include "DoubleJumpCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADoubleJumpCharacter::ADoubleJumpCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	//Setting Mesh
	sm = CreateDefaultSubobject<UStaticMeshComponent>("sm");
	sm->SetupAttachment(GetRootComponent());
	sm->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	//Setting Jump count
	JumpMaxCount = 2;

	//Setting SpringArm
	arm = CreateDefaultSubobject<USpringArmComponent>("arm");
	arm->SetupAttachment(GetRootComponent());
	arm->TargetArmLength = 500.f;
	arm->bUsePawnControlRotation = true;

	//Setting Up Camera
	camera = CreateDefaultSubobject<UCameraComponent>("camera");
	camera->bUsePawnControlRotation = false;

	//Attach Camera To SpringArm
	camera->SetupAttachment(arm, USpringArmComponent::SocketName);




}

// Called when the game starts or when spawned
void ADoubleJumpCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}
void ADoubleJumpCharacter::GoToHub()
{
	if (!UGameplayStatics::GetCurrentLevelName(this).Equals("HubWorld"), ESearchCase::IgnoreCase) UGameplayStatics::OpenLevel(this, "HubWorld");
}

// Called every frame
void ADoubleJumpCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADoubleJumpCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//Bind Jump
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ADoubleJumpCharacter::Jump);
	PlayerInputComponent->BindAction("Menu", IE_Pressed, this, &ADoubleJumpCharacter::GoToHub);
	//Bind Movement
	PlayerInputComponent->BindAxis("MoveForward", this, &ADoubleJumpCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ADoubleJumpCharacter::MoveRight);
	//Bind Camea Movement
	PlayerInputComponent->BindAxis("LookUp", this, &ADoubleJumpCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookRight", this, &ADoubleJumpCharacter::AddControllerYawInput);


}
void ADoubleJumpCharacter::MoveForward(float AxisValue) 
{
	if(AxisValue != 0.f)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, AxisValue);
	}

}
void ADoubleJumpCharacter::MoveRight(float AxisValue)
{
	if (AxisValue != 0.f)
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, AxisValue);
	}

}

