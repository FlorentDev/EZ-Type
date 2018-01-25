/**
 * \file entity.h
 * \brief The elementary things (moves, direction, collision, ...)
 * \author EZ-Type group: Thomas DELPY, Aymeric FAVARD, David CECCARELLI, Florent SALOU
 * \version Final
 * \date January 2018
**/

/**
 * \struct Position
 * \brief X and Y param for 2D position
**/
typedef struct {
	int x; /*!< Param in the x axe position */
	int y; /*!< Param in the y axe position */
} Position;

/**
 * \struct Speed
 * \brief Speed on X and Y axes
**/
typedef struct {
	float speedX; /*!< Speed on X axe */
	float speedY; /*!< Speed on Y axe */
} Speed;

/**
 * \struct Hitbox
 * \brief Box of an item on the screen which is use to calculate the collision between two elements
**/
typedef struct {
	Position pos; /*!< The position of the bottom left corner */
	int width; /*!< The width of the pic which is the virtual size of the item */
	int height; /*!< The height of the pic which is the virtual size of the item */
} Hitbox;

/**
 * \struct Direction
 * \brief Direction on X and Y axes
**/
typedef struct {
	int dirX; /*!< Direction on X axe */
	int dirY; /*!< Direction on Y axe */
} Direction;

/**
 * \fn int moveUp(Hitbox* hitbox, Position* pos, Speed speed)
 * \brief Change the position upward of an item if possible, a movement is possible if the entity doesn't go out of the screen
 *
 * \param hitbox The hitbox of the item to change the calcul of the collision
 * \param pos The position of the item to move it on the screen
 * \param speed The speed of the item to move it on the right distance
 * \return 1 if the movement could be done, 0 otherwise
**/
int moveUp(Hitbox* hitbox, Position* pos, Speed speed);

/**
 * \fn int moveDown(Hitbox* hitbox, Position* pos, Speed speed)
 * \brief Change the position downward of an item if possible, a movement is possible if the entity doesn't go out of the screen
 *
 * \param hitbox The hitbox of the item to change the calcul of the collision
 * \param pos The position of the item to move it on the screen
 * \param speed The speed of the item to move it on the right distance
 * \return 1 if the movement could be done, 0 otherwise
**/
int moveDown(Hitbox* hitbox, Position* pos, Speed speed);

/**
 * \fn int moveLeft(Hitbox* hitbox, Position* pos, Speed speed)
 * \brief Change the position to left of an item if possible, a movement is possible if the entity doesn't go out of the screen
 *
 * \param hitbox The hitbox of the item to change the calcul of the collision
 * \param pos The position of the item to move it on the screen
 * \param speed The speed of the item to move it on the right distance
 * \return 1 if the movement could be done, 0 otherwise
**/
int moveLeft(Hitbox* hitbox, Position* pos, Speed speed);

/**
 * \fn int moveRoght(Hitbox* hitbox, Position* pos, Speed speed)
 * \brief Change the position to right of an item if possible, a movement is possible if the entity doesn't go out of the screen
 *
 * \param hitbox The hitbox of the item to change the calcul of the collision
 * \param pos The position of the item to move it on the screen
 * \param speed The speed of the item to move it on the right distance
 * \return 1 if the movement could be done, 0 otherwise
**/
int moveRight(Hitbox* hitbox, Position* pos, Speed speed);

/**
 * \fn int checkCollision(Hitbox hitbox1, Hitbox hitbox2)
 * \brief check if two hitbox is in contact or not
 *
 * \param hitbox1 First item
 * \param hitbox2 Second item
 * \return 1 if 'hitbox1' and 'hitbox2' are colliding, 0 otherwise
**/
int checkCollision(Hitbox hitbox1, Hitbox hitbox2);
