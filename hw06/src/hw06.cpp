#include <hw06.h>

Hall create_hall(int hall_id, int rows, int seats_per_row) {
  Hall hall;
  hall.id = hall_id;
  hall.rows = rows;
  hall.seats_per_row = seats_per_row;

  for (int i = 0; i < rows; ++i) { // заполнение сидушек денисиками
    for (int j = 0; j < seats_per_row; ++j) {
      hall.seats.push_back({i, j, false});
    }
  }

  return hall;
}

Session create_session(int session_id, const std::string& movie_title, Hall& hall) {
  return Session {session_id, movie_title, hall}; // сессия с денисиками
}


bool reserve_seat(Session& session, int row, int seat_number) {
  for (Seat& seat : session.hall.seats) {
    if (seat.row == row && seat.number == seat_number) {
      if (!seat.is_reserved) {
        seat.is_reserved = true; // сидушка денисика зарезервирована успешно
        return true;
      }
      else { return false; } // сидушка денисика уже зарезервирована
    }
  }
  return false; // сидушка денисика не найдена
}

bool cancel_reservation(Session& session, int row, int seat_number) {
  for (Seat& seat : session.hall.seats) {
    if (seat.row == row && seat.number == seat_number) {
      if (seat.is_reserved) {
        seat.is_reserved = false; // сидушка денисика раззарезервирована успешно
        return true;
      }
      else { return false; } // сидушка денисика уже раззарезервирована
    }
  }
  return false; // сидушка денисика не найдена
}

int get_available_seats(const Hall& hall) {
  int available_seats = 0;

  for (const Seat& seat : hall.seats) { //найти количество мест без денисиков
    if (!seat.is_reserved) {
      ++available_seats;
    }
  }

  return available_seats;
}

void display_hall(const Hall& hall) {
  cout << get_available_seats(hall) << endl; // сколько мест без денисиков
}

