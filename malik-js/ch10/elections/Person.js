class Person {
  constructor(name, surname) {
    this.name = name
    this.surname = surname
  }

  get firstName() {
    return this.name
  }

  set firstName(val) {
    this.name = val
  }

  get lastName() {
    return this.surname
  }

  set lastName(val) {
    this.surname = val
  }

  equals(other) {
    return this.firstName === other.firstName && this.lastName === other.lastName
  }
}

module.exports = Person
