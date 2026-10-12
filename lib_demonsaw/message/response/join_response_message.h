// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _EJA_JOIN_RESPONSE_MESSAGE_
#define _EJA_JOIN_RESPONSE_MESSAGE_

#include <memory>

#include "json/json.h"
#include "json/json_message.h"
#include "json/json_value.h"
#include "json/value/json_info.h"
#include "json/value/json_join.h"

namespace eja
{
	class join_response_message final : public json_message
	{
	public:
		using ptr = std::shared_ptr<join_response_message>;

	private:
		join_response_message() : json_message(json_type::join, json_action::response) { }
		join_response_message(const json_message::ptr& message) : json_message(message, json_type::join, json_action::response) { }
		join_response_message(const json_value::ptr& value) : json_message(value, json_type::join, json_action::response) { }

	public:      
		virtual ~join_response_message() override { }

		// Accessor
		json_info::ptr get_info() { return json_info::create(shared_from_this()); }

		// Static
		static ptr create() { return ptr(new join_response_message()); }
		static ptr create(const json_message::ptr& message) { return ptr(new join_response_message(message)); }
		static ptr create(const json_value::ptr& value) { return ptr(new join_response_message(value)); }
	};
}

#endif
