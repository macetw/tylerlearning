from sqlalchemy import Column, ForeignKey, Integer, String
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import relation
from sqlalchemy import create_engine

Base = declarative_base()

engine = create_engine('sqlite:////var/www/data/adoptus.db')


class Child(Base):
    __tablename__ = 'child'

    id = Column(Integer, primary_key=True)
    firstName = Column(String(250), nullable=False)
    lastName = Column(String(250), nullable=False)
    caseId = Column(String(250), nullable=False)
    # Note, this is not a foreign key relation
    caseworkerEmail = Column(String(250), nullable=False)
    description = Column(String(1024))
    gender = Column(String(1))
   # TODO: add sibling-group-id
   # TODO: add birthDate
   # TODO: add listingDate

    @property
    def serialize(self):
        ##Return object data in easily serializeable format"""
        return {
            'firstname': self.firstName,
            'id': self.id,
            'description': self.description,
        }


class Photo(Base):
    __tablename__ = 'photo'

    id = Column(Integer, primary_key=True)
    childId = Column(Integer, ForeignKey('child.id'))
    child = relation(Child)
    description = Column(String(250))


Base.metadata.create_all(engine)
