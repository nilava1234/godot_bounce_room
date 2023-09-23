extends Node3D

var move_speed = 500.0
var rotation_speed = 1.0
var height_speed = 1.0

func _process(delta):
	# Movement
	var move_direction = Vector3()
	if Input.is_action_pressed("move_forward"):
		move_direction.z -= 1
	if Input.is_action_pressed("move_backward"):
		move_direction.z += 1
	if Input.is_action_pressed("strafe_left"):
		move_direction.x -= 1
	if Input.is_action_pressed("strafe_right"):
		move_direction.x += 1

	move_direction = move_direction.normalized()
	position += move_direction * move_speed * delta

	# Rotation
	var rotation = Vector2()
	if Input.is_action_pressed("rotate_left"):
		rotation.x -= 1
	if Input.is_action_pressed("rotate_right"):
		rotation.x += 1
	if Input.is_action_pressed("rotate_up"):
		rotation.y -= 1
	if Input.is_action_pressed("rotate_down"):
		rotation.y += 1

	rotation = rotation.normalized()
	rotate_x(rotation.y * rotation_speed * delta)
	rotate_y(rotation.x * rotation_speed * delta)

	# Height adjustment
	if Input.is_action_pressed("raise_camera"):
		position.y += height_speed * delta * move_speed
	if Input.is_action_pressed("lower_camera"):
		position.y -= height_speed * delta * move_speed
