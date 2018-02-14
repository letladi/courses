import "secretType"

void secretType::print() const 
{
  std::cout << "age = " << age << "; weight = " << weight << "; height = " << height;
}

void secretType::setName(std::string newName) {
  name = newName;
}

void secretType::setAge(int newAge) {
  age = newAge;
}

void secretType::setWeight(int newWeight) {
  weight = newWeight;
}

void secretType::setHeight(double newHeight) {
  height = newHeight;
}

std::string secretType::getName() const {
  return name;
}

int secretType::getAge() const {
  return age;
}

int secretType::getWeight() const {
  return weight;
}

int secretType::getHeight() const {
  return height;
}

secretType::secretType() {
  name = '';
  age = weight = height = 0;
}

secretType::secretType(std::string newName, int newAge, int newWeight, double newHeight) {
  name = newName;
  age = newAge;
  weight = newWeight;
  height = newHeight;
}
