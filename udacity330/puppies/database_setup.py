#!/usr/bin/python26

import sys

from sqlalchemy.schema import Column, ForeignKey 
from sqlalchemy import Integer, String, Date, Float

from sqlalchemy.ext.declarative import declarative_base

from sqlalchemy.orm import relation

from sqlalchemy import create_engine

Base = declarative_base()

class Shelter(Base):
  __tablename__ = 'shelter'

  name = Column( String(80), nullable = False )
  address = Column( String(80) )
  city = Column( String(80) )
  state = Column( String(2) )
  zipCode = Column( String(10) )
  website = Column( String(80) )
  id = Column( Integer, primary_key = True )

class Puppy(Base):
  __tablename__ = 'puppy'

  name = Column( String(80), nullable = False )
  dateOfBirth = Column( Date )
  id = Column( Integer, primary_key = True )
  gender = Column(String(1))
  weight = Column( Float )
  shelter_id = Column(Integer, ForeignKey('shelter.id'))

engine = create_engine( 'sqlite:///puppies.db' )

Base.metadata.create_all(engine)

