#include <hw06.h>
#include <gtest/gtest.h>

TEST(Hw06Tests, Test1)
{
    auto rows = 5, seats_per_row = 8;
    Hall hall = create_hall(1, rows, seats_per_row);
    Session session = create_session(1, "Die Denisiki: Karmanaya Reznya Billyardom", hall);

    auto avail_seats = get_available_seats(hall);
    auto expected_seats = rows * seats_per_row;
    EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test2)
{
  auto rows = 5, seats_per_row = 15;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Denisiki: Karmanaya Reznya Billyardom", hall);

  // reserve 2 seats
  auto reserved_seats = 2;
  reserve_seat(session, 1, 3);
  reserve_seat(session, 2, 5);

  auto avail_seats = get_available_seats(hall);
  auto expected_seats = rows * seats_per_row - reserved_seats;
  EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test3)
{
  auto rows = 3, seats_per_row = 5;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Denisiki: Karmanaya Reznya Billyardom", hall);

  // reserve 1 seat
  reserve_seat(session, 1, 3);
  cancel_reservation(session, 1, 3);

  auto avail_seats = get_available_seats(hall);
  auto expected_seats = rows * seats_per_row;
  EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test4)
{
  auto rows = 3, seats_per_row = 5;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Denisiki: Karmanaya Reznya Billyardom", hall);

  // reserve 1 seat
  reserve_seat(session, 1, 3);
  auto reserve_stat = reserve_seat(session, 1, 3);
  auto expected_stat = false;
  EXPECT_EQ(expected_stat, reserve_stat);
}

TEST(Hw06Tests, Test5) // проверка на нулевой зал
{
  auto rows = 0, seats_per_row = 0;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Denisiki: Karmanaya Reznya Billyardom", hall);

  auto avail_seats = get_available_seats(hall);
  auto expected_seats = 0;
  EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test6) // проверка на занятость всех мест
{
  auto rows = 3, seats_per_row = 3;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Denisiki: Karmanaya Reznya Billyardom", hall);

  // Reserve all seats
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < seats_per_row; ++j) {
      reserve_seat(session, i, j);
    }
  }

  auto avail_seats = get_available_seats(hall);
  auto expected_seats = 0;
  EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test7) // проверка на освобождение всех мест
{
  auto rows = 3, seats_per_row = 3;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Denisiki: Karmanaya Reznya Billyardom", hall);

  // бронь
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < seats_per_row; ++j) {
      reserve_seat(session, i, j);
    }
  }

  // отмена брони
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < seats_per_row; ++j) {
      cancel_reservation(session, i, j);
    }
  }

  auto avail_seats = get_available_seats(hall);
  auto expected_seats = rows * seats_per_row;
  EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test8) // проверка на бронь и отмену брони несуществующих мест
{
  auto rows = 3, seats_per_row = 3;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Denisiki: Karmanaya Reznya Billyardom", hall);

  // попытка брони несущ. места
  auto reserve_stat = reserve_seat(session, 5, 5);
  auto expected_stat = false;
  EXPECT_EQ(expected_stat, reserve_stat);

  // попытка отмены брони несущ. места
  auto cancel_stat = cancel_reservation(session, 5, 5);
  auto expected_cancel_stat = false;
  EXPECT_EQ(expected_cancel_stat, cancel_stat);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
