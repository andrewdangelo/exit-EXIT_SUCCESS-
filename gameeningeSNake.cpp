

//Snake
void GameEngine::initSnake()
{
	
	srand(time(0));

	int x = rand() % width;
	int y = rand() % height;

	// Check if the location is occupied
	while (field[y][x] != nullptr) {
		// Choose a new random location
		x = rand() % width;
		y = rand() % height;
	}

	// Create a new Snake object and add it to the field
	field[y][x] = new Snake(x, y);

}
void GameEngine::moveSnake()
{
	int cap_x = captain->getX();
	int cap_y = captain->getY();
	int snake_x = snake->getX();
	int snake_y = snake->getY();
	char direction;
	if (cap_x-snake_x<0 && cap_y-snake_y<0 )
	{
		direction='w';
		if (dynamic_cast<Veggie*>(field[snake_x-1][snake_y]) != nullptr ) {
			direction='a';
			if(dynamic_cast<Veggie*>(field[snake_x][snake_y-1]) != nullptr || snake_y-1<0)
				
				{direction='d';
				if(dynamic_cast<Veggie*>(field[snake_x][snake_y+1]) != nullptr || snake_y+1>width)
					{direction='s';}
				}
		}
	}
	else if(cap_x-snake_x>0 && cap_y-snake_y>0 )
	{
		direction='s';
		if (dynamic_cast<Veggie*>(field[snake_x+1][snake_y]) != nullptr ) {
			direction='d';
			if(dynamic_cast<Veggie*>(field[snake_x][snake_y+1]) != nullptr || snake_y+1>width)
			{	direction='a';
				if(dynamic_cast<Veggie*>(field[snake_x][snake_y-1]) != nullptr || snake_y-1<0)
					{direction='w';}
			}
		}
	}
	else if(cap_x-snake_x==0 && cap_y-snake_y<0 )
	{
		direction='a';
		if (dynamic_cast<Veggie*>(field[snake_x][snake_y-1]) != nullptr ) {
			direction='s';
			if(dynamic_cast<Veggie*>(field[snake_x+1][snake_y]) != nullptr || snake_x+1>height)
			{	direction='w';
				if(dynamic_cast<Veggie*>(field[snake_x-1][snake_y]) != nullptr || snake_x-1<0)
					{direction='d';}
			}
		}
	}
	else if(cap_x-snake_x==0 && cap_y-snake_y>0 )
	{
		direction='d';
		if (dynamic_cast<Veggie*>(field[snake_x][snake_y+1]) != nullptr ) {
			direction='s';
			if(dynamic_cast<Veggie*>(field[snake_x+1][snake_y]) != nullptr || snake_x+1>height)
			{	direction='w';
				if(dynamic_cast<Veggie*>(field[snake_x-1][snake_y]) != nullptr || snake_x-1<0)
					{direction='a';}
			}
		}
	}
	else if(cap_x-snake_x>0 && cap_y-snake_y==0 )
	{
			direction='s';
		if (dynamic_cast<Veggie*>(field[snake_x+1][snake_y]) != nullptr ) {
			direction='d';
			if(dynamic_cast<Veggie*>(field[snake_x][snake_y+1]) != nullptr || snake_y+1>width)
			{	direction='a';
				if(dynamic_cast<Veggie*>(field[snake_x][snake_y-1]) != nullptr || snake_y-1<0)
				{	direction='w';}
			}
		}
	}
	else if(cap_x-snake_x<0 && cap_y-snake_y==0 )
	{
			direction='w';
		if (dynamic_cast<Veggie*>(field[snake_x-1][snake_y]) != nullptr ) {
			direction='d';
			if(dynamic_cast<Veggie*>(field[snake_x][snake_y+1]) != nullptr || snake_y+1>width)
			{	direction='a';
				if(dynamic_cast<Veggie*>(field[snake_x][snake_y-1]) != nullptr || snake_y-1<0)
				{	direction='s';}
			}
		}
	}
	switch (direction)
	{
	case 'w':
		
		if (dynamic_cast<Rabbit*>(field[snake_x-1][snake_y]) != nullptr)
		{
			/* code for skipping 5 ticks */
		}
		field[snake_x-1][snake_y]=snake;
		break;
		case 'a':
		
		if (dynamic_cast<Rabbit*>(field[snake_x][snake_y-1]) != nullptr)
		{
			/* code for skipping 5 ticks */
		}
		field[snake_x][snake_y-1]=snake;
		break;
		case 's':
		
		if (dynamic_cast<Rabbit*>(field[snake_x+1][snake_y]) != nullptr)
		{
			/* code for skipping 5 ticks */
		}
		field[snake_x+1][snake_y]=snake;
		break;
		case 'd':
		
		if (dynamic_cast<Rabbit*>(field[snake_x][snake_y+1]) != nullptr)
		{
			/* code for skipping 5 ticks */
		}
		field[snake_x][snake_y+1]=snake;
		break;
	}
}
