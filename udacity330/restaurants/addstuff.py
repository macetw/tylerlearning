#!/usr/bin/python26

from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from database_setup import Base, Restaurant, MenuItem, engine

Base.metadata.bind = engine
DBSession = sessionmaker(bind = engine)
session = DBSession()

myRestaurant = Restaurant(name = "Pizza Palace")
session.add(myRestaurant)
session.commit()

cheesepizza = MenuItem( name="Cheese Pizza", description="this is a cheese pizza", course="dinner", price="$9.00", restaurant=myRestaurant)
session.add(cheesepizza)
session.commit()
session.query(Restaurant).all()



